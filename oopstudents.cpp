#include<iostream>
#include<fstream>
#include<string>

class Student
{
private:
    string name, form;
    int m1, m2, m4, m3;
    static int c;
public:
    void setIn()
    {
        cin >> name >> form;
        cin >> m1 >> m2 >> m3 >> m4;
    }
    static int counter();
    void getIn(ofstream &v)
    {
        v << name << " " << form << " " << m1 << " " << m2 << " " << m3 << " " << m4;
    }
};
int Student::c = 0;
int Student:: counter()
{
    return c++;
}
bool check(string a)
{
    if (a.find('2')!=string::npos)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    int n = 2;
    Student* list = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cout<<list[i].counter()<<endl<<endl;
        list[i].setIn();
    }
    ofstream Q("abc.txt");
    for (int i = 0; i < n; i++)
    {
        list[i].getIn(Q);
        if (i != n - 1)
        {
            Q << endl;
        }
    }
    Q.close(); ifstream Z("abc.txt"); ofstream X("def.txt"); string t;
    while (!Z.eof())
    {
        getline(Z, t);
        if (check(t))
        {
            X <<t<<endl;
        }
    }
    Z.close(); X.close(); return INT16_MIN;
}
