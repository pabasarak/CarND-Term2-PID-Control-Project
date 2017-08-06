#include "PID.h"
#include "math.h"
//#include <iostream.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

bool pid_Tuned = false;

const double tolerance= 0.0001;  //0.0001;

void PID::Init(double Kp, double Ki, double Kd) {

 this->Kp=Kp;
  this->Kd=Kd;
  this->Ki=Ki;
  this->p_error=0.3;
  this->d_error=0.3;
  this->i_error=0.001;
  
}

void PID::UpdateError(double cte) {

 double p[] ={Kp,Ki,Kd};
  double dp[]={p_error,i_error,d_error};
    if (TotalError() > tolerance || (fabs(cte) > 0)) {
	 //last_optimize_index = (last_optimize_index + 1) % 2;
       

    switch (current_state) {
      case 0: {
        p[last_optimize_index] += dp[last_optimize_index];
        current_state = 1;
        break;
      }
      case 1: {
        if (fabs(cte) < fabs(best_error)) {
          best_error = cte;
		
		  dp[last_optimize_index] *= 1.1;
		
          current_state = 0;
        } else {
		
		  p[last_optimize_index] -= 2 * dp[last_optimize_index];
		
          current_state = 2;
        }
        break;
      }
      case 2: {
        if (fabs(cte) < fabs(best_error)) {
          best_error = cte;
          dp[last_optimize_index] *= 1.1;
		pid_Tuned = true;
        } else {
          p[last_optimize_index] += dp[last_optimize_index];
          dp[last_optimize_index] *= 0.9;
        }
        current_state =0;
	last_optimize_index = (last_optimize_index + 1) % 3;
        break;
      }
      case 3: {
        last_optimize_index = (last_optimize_index + 1) % 3;
        current_state = 0;
        break;
      }
	}
    
    p_error=dp[0];
    i_error=dp[1];
    d_error=dp[2];
    Kp=p[0];
    Ki=p[1];
    Kd=p[2];
  }
}

double PID::TotalError() {

	 return (p_error + i_error +d_error);
}

