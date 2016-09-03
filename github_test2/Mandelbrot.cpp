#include "stdafx.h"
#include "complex.h"
#include "MyForm.h"

void ConsoleCLR::MyForm::my_callback(Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
   // why did System::Windows::Forms:: need to be added?

   //MessageBox::Show(e->KeyChar.ToString());
   
   static complex center(-0.5, 0);
   static complex range(2, 2);

   switch (e->KeyChar) {
   case 'w':
      center.imag -= range.imag*0.1;
      break;
   case 's':
      center.imag += range.imag*0.1;
      break;
   case 'a':
      center.real -= range.real*0.1;
      break;
   case 'd':
      center.real += range.real*0.1;
      break;
   case 'e':
      range.real /= 2;
      range.imag /= 2;
      break;
   case 'q':
      range.real *= 2;
      range.imag *= 2;
      break;
   }

   

   pictureBox1->Image = make_bitmap(center, range);


}

System::Drawing::Bitmap^ ConsoleCLR::MyForm::make_bitmap(complex center, complex range) {
   //label1->Text = L"remote";
   
   complex C;
   
   int img_height = 300;
   int img_width = 300;
   
   Bitmap^ my_bitmap = gcnew Bitmap(img_height, img_width, Imaging::PixelFormat::Format24bppRgb);
   for (int ii = 0; ii < img_height; ii++) {
      for (int jj = 0; jj < img_width; jj++) {

         C.real = ((double)(jj) / (img_width - 1) - 0.5) * range.real + center.real;
         C.imag = ((double)(ii) / (img_height - 1) - 0.5) * range.imag + center.imag;
         int depth = calc_depth(ii, jj, C);

         my_bitmap->SetPixel(jj, ii, Color::FromArgb(depth, 0, 0));
      }
   }

   return my_bitmap;
}

int ConsoleCLR::MyForm::calc_depth(int ii, int jj, complex C) {
   int max_depth = 255;
   
   complex z = C;

   int depth;
   for (depth = 0; depth < max_depth; depth++) {
      if (z.sq_len() > 4) break;
      z = z*z + C;
   }

   return depth;
}


using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
int main(array<String^>^ args) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   ConsoleCLR::MyForm form;
   Application::Run(%form);
   return 0;
}

// ## hoarding

//Console::WriteLine(my_bitmap->Height);

//return gcnew Bitmap(L"my_image.jpg");

//char pixels[30000];
//for (char val : pixels) {
//   val = 0;
//}

//for (int ii = 0; ii < 30000; ii++) {
//   pixels[ii] = 0;
//}


//IntPtr scan0(pixels);
//return gcnew Bitmap(img_height, img_width, img_width * 3, Imaging::PixelFormat::Format24bppRgb, scan0);