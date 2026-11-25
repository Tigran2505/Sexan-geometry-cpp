#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592;

class Sexan {
private:
double a;
double b;
double c;
double alphaDeg;

double toRad(double deg) const {
return deg * PI / 180;
}
double toDeg(double rad) const {
return rad * 180 / PI;
}

public:
Sexan(double baseA, double baseB, double lengC, double angleAlphaDeg) {
bool valid = true;

if (baseA <= 0 || baseB <= 0 || lengC <= 0) {
cout << "koxmery petq e linen drakan (>0)" << endl;
valid = false;
}
if (angleAlphaDeg <= 0 || angleAlphaDeg >= 180) {
cout << "ankyunnery petq e linen 0<L<180" << endl;
}

a = baseA;
b = baseB;
c = lengC;
alphaDeg = angleAlphaDeg;

}

double height() const {
return c * sin(toRad(alphaDeg));
}
double area() const {
double h = height();
return ((a + b)/2) * h;

}
double BottomRightAngle() const {
double h = height();
double dx = (a - b) - c * cos(toRad(alphaDeg));
double RightBaseD = sqrt(dx * dx + h * h);
return toDeg(asin(h / RightBaseD));
}
double TopLeftAngle() const {
return 180 - alphaDeg;
}
double TopRightAngle() const{
double toprightangle = BottomRightAngle();
return 180 - toprightangle;
}
double RightBaseD() const {
double h = height();
double dx = (a - b) - c * cos(toRad(alphaDeg));
return sqrt(dx * dx + h * h);
}

void printAll()const {
cout << "\nBardzrutyun (h) = " << height() << endl;
cout << "\n Aj srunq (d) = " << RightBaseD() << endl;
cout << "\n Makeres (S) = " << area() << endl;
cout << "\n Nerqevi aj ankyun (L4) = " << BottomRightAngle() << endl;
cout << "\n Verevi dzax ankyun (L2) = " << TopLeftAngle() << endl;
cout << "\n Verevi aj ankyun (L3) = " << TopRightAngle() << endl;
}
};

int main() {
double a, b, c, alpha;

cout << "Mutqagreq nerqevi himqy (a): ";
cin >> a;

cout << "Mutqagreq verevi himqy (b): ";
cin >> b;

cout << "Mutqagreq dzax srunqy (c): ";
cin >> c;

cout << "Mutqagreq nerqevi dzax ankyuny (0...180 astijan) (L1) ";
cin >> alpha;

Sexan s(a, b, c, alpha);
s.printAll();

return 0;
}