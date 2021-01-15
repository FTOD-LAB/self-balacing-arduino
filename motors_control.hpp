#include "Arduino.h"
#ifndef _MOTORS_CONTROL_HPP_
#define _MOTORS_CONTROL_HPP_

class Motors{
public:
    enum MotorsStatus{ STOP, FORWARD, BACKWARD };
    enum MotorDirection {POSITIVE, NEGATIVE};
    //Empty motors
    Motors():_PIN_PWM1(5),_PIN_PWM2(6),_PIN_Ctrl2(4),_PIN_Ctrl1(7){

            pinMode(_PIN_Ctrl1, OUTPUT);
            pinMode(_PIN_Ctrl2, OUTPUT);

            analogWrite(_PIN_PWM1, 0);
            analogWrite(_PIN_PWM2, 0);

            _status = STOP;
            _m1 = MotorDirection::POSITIVE;
            _m2 = MotorDirection::POSITIVE;

        };
    
    inline void set(int power){
        //POWER SHOULD BE BETWEEN -255, 255
        if (power < 0){
            set_direction(MotorsStatus::BACKWARD);
            analogWrite(_PIN_PWM1, -power);
            analogWrite(_PIN_PWM2, -power);
        }
        else{
            set_direction(MotorsStatus::FORWARD);
            analogWrite(_PIN_PWM1, power);
            analogWrite(_PIN_PWM2, power);
        }
    };

    inline void reverse_m2_direction(){
      if(_m2 == MotorDirection::POSITIVE){
        _m2 = MotorDirection::NEGATIVE;
      }
      if(_m2 == MotorDirection::NEGATIVE){
        _m2 = MotorDirection::POSITIVE;
      }
    };
    inline void set_direction(MotorsStatus s){
        if (s == MotorsStatus::FORWARD && _status != MotorsStatus::FORWARD){
          //TODO, should be both HIGH or LOW, to modify this class
            digitalWrite(_PIN_Ctrl1,LOW);
            digitalWrite(_PIN_Ctrl2,HIGH);
        }
        if (s == MotorsStatus::BACKWARD && _status != MotorsStatus::BACKWARD){
            digitalWrite(_PIN_Ctrl1,HIGH);
            digitalWrite(_PIN_Ctrl2,LOW);
        }
    };

    //inline void turn_around(){
    //    if (_status = MotorsStatus::FORWARD){
    //        pinMode(_PIN_Ctrl1)
    //    }
    //};

private:
    int _PIN_PWM1;
    int _PIN_PWM2;
    int _PIN_Ctrl1;
    int _PIN_Ctrl2;
    MotorDirection _m1;
    MotorDirection _m2;
    MotorsStatus _status;
};

#endif // _MOTORS_CONTROL_HPP_
