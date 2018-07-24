#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <cassert>

template<typename T>
class Singleton
{
public:
	Singleton(T& instance)
	{
		assert(!sfpInstance || (sfpInstance==&instance));
		sfpInstance = &instance;
	}

#ifdef USE_DESTRUCTORS
	~Singleton()
	{
		sfpInstance = 0L;
	}
#endif

	static T& getInstance()
	{
		assert(sfpInstance);
		return *sfpInstance;
	}
private:
	static T*	sfpInstance;
};

template<typename T> T* Singleton<T>::sfpInstance(0L);

#endif /* SINGLETON_H_ */
