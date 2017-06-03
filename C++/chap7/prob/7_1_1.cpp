#include <iostream>

using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int gasoline) 
        : gasolineGauge(gasoline)
    { }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int elect,int gasoline) 
        : Car(gasoline), electricGauge(elect)
    { }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int water,int elect, int gasoline) 
        : waterGauge(water), HybridCar(elect,gasoline)
    { }
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};

int main(void)
{
    HybridWaterCar Car(30,40,50);
    Car.ShowCurrentGauge();
}
