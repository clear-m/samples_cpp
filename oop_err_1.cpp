
class Foo
{
public:
    Foo()
    {
        return;
    }
    Foo(Foo &f)
    {
        return;
    }
    Foo(int b)
    {
        a = new int[b];
    }
    ~Foo()
    {
        delete a;
    }

private:
    int *a;
};

class Bar : /*public*/ Foo // private inheritance
{
public:
    Bar(int b)
    {
        a = new char[b];
    }
    ~Bar()
    {
        delete a; // ub delete on array
    }

private:
    char *a;
};

int main(int argc, char **argv)
{
    /*
    //INFO: uncomment and find out what is wrong with the code
    Foo *f = new Foo(100);
    Foo *b = new Bar(200); // private inheritance - ‘Foo’ is an inaccessible base of ‘Bar’
    *f = *b;               // slicing
    f = b;
    delete f;
    delete b;
    */
    return 0;
}