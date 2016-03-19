#include"TSStack.h"
template<typename T>
TSStack<T>::TSStack(){};
template<typename T>
TSStack<T>::TSStack(const TSStack& other)
{
	std::lock_guard<std::mutex> lock(other.m_Mutex);
	data = other.data;
}
template<typename T>
bool TSStack<T>::Empty() const
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	return data.empty();
}
template<typename T>
void TSStack<T>::Push(T val)
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	data.push(val);
}
template<typename T>
void TSStack<T>::Pop(T& value)
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (data.empty()) throw StackEmptyException();
	value = data.top();
	data.pop();
}
template<typename T>
std::shared_ptr<T> TSStack<T>::Pop()
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (data.empty()) throw StackEmptyException();
	std::shared_ptr<T> const res(new T(data.top()));
	data.pop();
	return res;
}
