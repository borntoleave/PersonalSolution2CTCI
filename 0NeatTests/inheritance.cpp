class BaseClass{
public:
    int a;
    void test1();
    virtual void printFunc(){
    cout<<"This is BaseClass."<<endl;
    }
protected:
    int b;
    void test2();
private:
    int c;
};
class DerivedClassA : public BaseClass{
public:
    void printFunc(){
    cout<<"This is DerivedClassA."<<endl;
    }
    void testA(){
       cout<<a<<endl
       <<b<<endl
       <<c<<endl;//报错
    }
private:
    int d;
};
