#pragma once
// TODO:
// const complex& z

//using namespace std;

class complex {
public:
   double real;
   double imag;

   complex() {}
   complex(double a, double b) : real(a), imag(b) {}

   complex operator+ (complex z) {
      complex result;
      result.real = real + z.real;
      result.imag = imag + z.imag;
      return result;
   }

   complex operator- (complex z) {
      complex result;
      result.real = real - z.real;
      result.imag = imag - z.imag;
      return result;
   }

   complex operator* (complex z) {
      complex result;
      result.real = real*z.real - imag*z.imag;
      result.imag = real*z.imag + imag*z.real;
      return result;
   }

   complex operator= (complex z) {
      real = z.real;
      imag = z.imag;
      return *this;
   }

   //complex negate(complex& z) {
   //   z.real = -z.real;
   //   z.imag = -z.imag;
   //   return z;
   //}

   complex conj() {
      imag = -imag;
      return *this;
   }

   double sq_len() {
      return real*real + imag*imag;
   }
};

//int main2() {
//   complex z1 = { 1, 2 };
//   complex z2 = { 3, 8 };
//   complex z;
//   z = z1 * z2;
//   cout << "hello\n" << z.real << " " << z.imag << '\n';
//   z1.negate(z);
//   cout << "hello\n" << z.real << " " << z.imag << '\n';
//   return 0;
//}
