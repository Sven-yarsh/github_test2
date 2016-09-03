#pragma once
#include "complex.h" // why do I need this now, but didn't before?

namespace ConsoleCLR {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   /// <summary>
   /// Summary for MyForm
   /// </summary>
   public ref class MyForm : public System::Windows::Forms::Form
   {
   public:

      MyForm(void) {
         InitializeComponent();

         // MY CODE
         //this->KeyPreview = true;
         this->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::my_callback); // why MyForm:: ?

                                                                                   //pictureBox1->Image = make_bitmap(center, range);
      }


      Bitmap^ make_bitmap(complex center, complex range);
      int calc_depth(int ii, int jj, complex C);
   private: void my_callback(Object^ Sender, KeyPressEventArgs^ e);

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~MyForm()
      {
         if (components)
         {
            delete components;
         }
      }
   private: System::Windows::Forms::PictureBox^  pictureBox1;
   private: System::Windows::Forms::Label^  label1;
   protected:

   private:
      /// <summary>
      /// Required designer variable.
      /// </summary>
      System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      void InitializeComponent(void)
      {
         this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
         this->label1 = (gcnew System::Windows::Forms::Label());
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
         this->SuspendLayout();
         // 
         // pictureBox1
         // 
         this->pictureBox1->Location = System::Drawing::Point(95, 53);
         this->pictureBox1->Name = L"pictureBox1";
         this->pictureBox1->Size = System::Drawing::Size(500, 500);
         this->pictureBox1->TabIndex = 0;
         this->pictureBox1->TabStop = false;
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(47, 21);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(128, 13);
         this->label1->TabIndex = 1;
         this->label1->Text = L"controls: W, A, S, D, Q, E";
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(635, 578);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->pictureBox1);
         this->Name = L"MyForm";
         this->Text = L"MyForm";
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   };
}
