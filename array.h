#pragma once

#include <iostream>

class array
{
  private:
  int *arr;
  int size;


  int sortedsearch(int target,int left,int right)
  {
    if(left>right)
    {
      return -1;
    }

    int mid = (left + right)/2;

    if(arr[mid] == target) return mid;
    else if(arr[mid]>target)
    {
      return sortedsearch(target,left,mid-1);
    }
    else //arr[mid]<target
    {
      return sortedsearch(target,mid + 1,right);
    }

  }

  void mergesort(int s,int e)
  {
    if(s>=e) return;

    int mid = (s+e)/2;

    mergesort(s,mid);//leftsort
    mergesort(mid+1,e);//rightsort
    merge(s,e);//merge
  }

  void merge(int s,int e)
  {
      int mid = (s+e)/2;

      int len1 = mid - s+1;
      int len2 = e-mid;

      int *first = new int[len1];
      int *second = new int[len2];

      int arrindex = s;

      for(int i = 0;i<len1;i++)
      {
        first[i] = arr[arrindex++];
      }

      int k = mid+1;
      for(int i = 0;i<len2;i++)
      {
        second[i] = arr[arrindex++];
      }

      int index1 = 0,index2 = 0;
      arrindex = s;

      while(index1<len1 && index2<len2)
      {
        if(first[index1]<second[index2])
        {
          arr[arrindex++] = first[index1++];
        }else{
          arr[arrindex++] = second[index2++];
        }
      }

      while(index1 < len1)
      {
        arr[arrindex++] = first[index1++];
      }

      while(index2 < len2)
      {
        arr[arrindex++] = second[index2++];
      }
      delete[] first;
      delete[] second;

  }

  public:

  array(int *ar, int s) : arr(ar), size(s) {}

   int search(int target)
  {
    for(int i = 0;i<size;i++)
    {
      if(arr[i] == target) return i;
    }

    return -1;
  }

  int ssearch(int target)
  {
    return sortedsearch(target,0,size-1);
  }

  void sort()
  {
    if(size>1)  mergesort(0,size-1);
  }

  void display()
  {
    for(int i = 0;i<size;i++)
    {
      std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
  }

};
