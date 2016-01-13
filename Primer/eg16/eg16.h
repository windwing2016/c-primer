#ifndef EG16
#define EG16
#include <iostream>
#include <vector>
#include <memory>   //使用shared_ptr指针


using namespace std;

template <typename T>
class  Blob
{
public:
    typedef  T value_type;
    typedef typename  std::vector<T>::size_type  size_type;  //构造函数
    Blob();
    Blob(std::initializer_list<T> il);

    size_type size() const //Blob 中元素数目
    {
        return data->size();
    }

    bool empty()  const
    {
       return data->empty();
    }

    void push_back(const T &t)
    {
        data->push_back(t);
    }

    void push_back( T &&t)
    {
        data->push_back(std::move(t));
    }
    void pop_back();

    T& back();

    T& operator[](size_type i);


private:
    shared_ptr<std::vector<T>> data;   //若data[i]无效 抛出msg
    void check(size_type i, const std::string &msg) const;


   //  Blob() {}
};












#endif // EG16

