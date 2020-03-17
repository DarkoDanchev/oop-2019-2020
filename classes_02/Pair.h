#pragma once 


template <typename K, typename V>
class Pair 
{
private: 
   K key;
   V value;
public: 
   Pair(K key, V value)
   {
       this->key = key;
       this->value = value;
   }
   K getKey() const
   {
       return this->key;
   }
   void setKey(K key)
   {
       this->key = key;
   }
   V getValue() const
   {
       return this->value;
   }
   void setValue(V value)
   {
       this->value = value;
   }
};