class Operator {
    friend ostream& operator<<(ostream&, Operator&);
    friend istream& operator>>(istream&, Operator&);
public:
    long factorial();
    long factorial(int);
private:
    int n;
    long hasil;
};

long Operator::factorial() {
    long fak = 1;
    for (int i = 1; i <= n; i++) 
        fak = fak * i;
    return fak;
}

long Operator::factorial(int n) {
    if ((n == 0) || (n == 1)) return 1;
    else return n * factorial(n - 1);
}
