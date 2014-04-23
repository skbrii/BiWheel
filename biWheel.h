#ifndef biWheel_h
#define biWheel_h

class biWheel
{
  public:
    biWheel(int in1, int in2, int in3, int in4);
    void leftMotorForward();
    void leftMotorBackward();
    void leftMotorStop();
    void rightMotorForward();
    void rightMotorBackward();
    void rightMotorStop();
    
  private:
    int _in1;
    int _in2;
    int _in3;
    int _in4;
}

#endif
