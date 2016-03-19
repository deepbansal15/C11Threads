#ifndef _TSSTACK_H
#define _TSSTACK_H
#include<thread>
#include<mutex>
#include<exception>
#include<stack>
#include<memory>
struct StackEmptyException : std::exception
{
	const char* what() const throw();
};
template<typename T>
class TSStack
{
public:
	TSStack();
	~TSStack();
	bool Empty() const;
	std::shared_ptr<T> Pop();
	void Pop(T& value);
	void Push(T val);
private:
	std::stack<T> data;
	mutable std::mutex m_Mutex;
	TSStack(const TSStack& other);
	TSStack& operator= (const TSStack&) = delete;
};
#endif