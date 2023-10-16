#include "sequential-list.h"

using namespace std;
SequentialList::SequentialList(unsigned int cap) {
    capacity_ = cap;
    data_= new int[capacity_];
    size_ = 0;
}


SequentialList::~SequentialList() {
    delete data_;
    data_= nullptr;
}


unsigned int SequentialList::size() const {
    return size_;
}


unsigned int SequentialList::capacity() const {

    return capacity_;
}


bool SequentialList::empty() const {

    if( size_==0)
        return true;

    else
        return false;
}


bool SequentialList::full() const {
    if (size_ == capacity_)
        return true;

    else
        return false;
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    if( index>size_-1 || index<0){
        return data_[size_-1];
    }
    else
        return data_[index];
}


unsigned int SequentialList::search(DataType val) const {

    for(int count = 0; count<=size_-1; count ++)
    {
        if (data_[count]== val)
        {

            return count;
        }
    }
    return size_;
}


void SequentialList::print() const {

    for (int ind  = 0; ind <=size_-1; ind++) {
        cout << data_[ind] << " ";
    }

}


bool SequentialList::insert(DataType val, unsigned int index) {
    if (index <= size_ && size_ + 1 <= capacity_) {
        for (int count = size_; count > index; count--) {
            data_[count] = data_[count - 1];
        }
        data_[index] = val;
        size_ += 1;
        return true;
    }
    else
    {
        return false;
    }
}






bool SequentialList::insert_front(DataType val) {
    if(size_<capacity_)
    {
        for (int count = size_-1; count>=0;count--)
        {
            data_[count+1]= data_[count];
        }
        data_[0] = val;
        size_+=1;
        return true;
    }
    else
        return false;
}


bool SequentialList::insert_back(DataType val) {
    if (size_<capacity_)
    {
        data_[size_]=val;
        size_+=1;
        return true;
    }

    return false;
}


bool SequentialList::remove(unsigned int index) {
    if (size_>0 && index<=size_-1)
    {
        for(int count =index; count<=size_;count++)
        {
            data_[count] = data_[count+1];
        }
        size_-=1;
        return true;

    }
    return false;
}


bool SequentialList::remove_front() {
    if (size_>0)
    {
        for(int count =0; count<=size_-1;count++)
        {
            data_[count] = data_[count+1];
        }
        size_-=1;
        return true;

    }
    return false;
}


bool SequentialList::remove_back() {
    if(size_>0)
    {
        data_[size_-1]=NULL;
        size_-=1;
        return true;
    }
    else
        return false;
}


bool SequentialList::replace(unsigned int index, DataType val) {
    if(index>size_-1 || index<0)
    {
        return false;
    }
    else
    {
        data_[index]=val;
        return true;
    }


}
