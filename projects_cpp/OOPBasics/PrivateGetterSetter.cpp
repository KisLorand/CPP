#include <iostream>

class Stove
{
    private:
        int temperature = 0;

    public:
        Stove()
        {

        }

        Stove(int temp)
        {
            setTemperarture(temp);
        }

        // temperature getter -> make a private attribute readable
        int getTemperature() 
        {
            return temperature;
        }

        void setTemperarture(int temperature)
        {
            if (temperature < 0 )
            {
                this->temperature = 0;
            }
            else if (temperature >= 420)
            {
                this->temperature = 420;
            }
            else
            {
                this->temperature = temperature;
            }
        }
};

class TimerStove : public Stove
{
    private:
    public:
        TimerStove()
        {

        }

        void timer(int time)
        {
            if (time > 100)
            {
                time = 100;
            }
            else if (time < 0)
            {
                time = 1;
            }

            for(int i=0; i<time; i++)
            {
                std::cout << time << ' ';
            }
            std::cout << '\n';
        }
};

int main()
{
    Stove stove1;

    stove1.setTemperarture(100);
    std::cout << "Stove temeperature : " << stove1.getTemperature() << " C\n";

    Stove stove2(-3);
    std::cout << "Stove temeperature : " << stove2.getTemperature() << " C\n";
    stove2.setTemperarture(100000);
    std::cout << "Stove temeperature : " << stove2.getTemperature() << " C\n";

    TimerStove timerStove1();

    return 0;
}