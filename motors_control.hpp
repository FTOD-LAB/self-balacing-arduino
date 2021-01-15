#ifndef _MOTORS_CONTROL_HPP_
#define _MOTORS_CONTROL_HPP_

class Motors{
public:
    enum MotorsStatus{ STOP, FORWARD, BACKWARD }
    //Empty motors
    Motors():_PIN_PWM1(5),_PIN_PWM2(6),_PIN_Ctrl2(4),_PIN_Ctrl1(7){

            pinMode(_PIN_Ctrl1, OUTPUT);
            pinMode(_PIN_Ctrl2, OUTPUT);

            analogWrite(_PIN_PWM1, 0);
            analogWrite(_PIN_PWM2, 0);

            _status = STOP;
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

    inline void set_direction(MotorsStatus s){
        if (s == MotorsStatus::FORWARD){
            digitalWrite(_PIN_PWM1,HIGH);
            digitalWrite(_PIN_PWM2,HIGH);
        }
        if (s == MotorsStatus::BACKWARD){
            digitalWrite(_PIN_PWM1,LOW);
            digitalWrite(_PIN_PWM2,LOW);
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
    MotorsStatus _status;
};

#endif // _MOTORS_CONTROL_HPP_
