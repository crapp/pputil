#ifndef SIMPLE_PPUTIL
#define SIMPLE_PPUTIL

#include <string>

class StreamOp
{
public:
    StreamOp();
    StreamOp(std::string s);
    StreamOp(const StreamOp &) = default;
    StreamOp(StreamOp &&) = default;
    virtual ~StreamOp();

    void setMyString(std::string mystring);
    std::string getMyString() const;

    friend std::ostream &operator<<(std::ostream &stream, const StreamOp &so)
    {
        stream << so.getMyString();
        return stream;
    }

private:
    /* data */

    std::string mystring;
};

#endif /* ifndef SIMPLE_PPUTIL */
