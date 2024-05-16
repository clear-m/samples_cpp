#include <string>
#include <iostream>

/*
//INFO: original quiz
class PrinterHP
{
public:
    void print(const std::string& text) const
    {
        // logic
    }
};

class DocumentPDF
{
private:
    PrinterHP printer;
public:
    void print(const std::string& text) const
    {
        // logic
    }
};
*/

//INFO: refactored to
class IPrinter
{
public:
    virtual void print(const std::string &text) const = 0;
};

class IDocument
{
public:
    virtual std::string text() const = 0;
};

class PrinterHP : public IPrinter
{
public:
    void print(const std::string &text) const
    {
        std::cout << "text: " << text << std::endl;
    }
};

class DocumentPDF : public IDocument
{
public:
    std::string text() const
    {
        return "text";
    }
};

int main()
{
    // DocumentPDF doc;
    // doc.print("Text");

    DocumentPDF doc;
    PrinterHP printer;
    printer.print(doc.text());

    return 0;
}
