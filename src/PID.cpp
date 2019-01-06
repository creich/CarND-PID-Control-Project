#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
   //TODO what will happen if int_cte will overflow?
   int_cte = 0.0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
   this->Kp = Kp;
   this->Ki = Ki;
   this->Kd = Kd;
}

double PID::steer(double cte) {
   if(!prev_cte_set) {
      prev_cte = cte;
      prev_cte_set = true;
   }
   double diff_cte = cte - prev_cte;
   int_cte += cte;
   prev_cte = cte;
   return -Kp * cte - Ki * diff_cte - Kd * int_cte;
}

void PID::UpdateError(double cte) {

}

double PID::TotalError() {
}

