#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include <iostream>
#include <set>
#include <string>

namespace ver_1
{
    //////////////////////////////////////////////////////////////////////////////////////
    template <typename TSource, typename... TEventArgs>
    class Observer
    {
    public:
        virtual void update(TSource &, TEventArgs... args) = 0;
        virtual ~Observer() = default;
    };

    //////////////////////////////////////////////////////////////////////////////////////
    template <typename TSource, typename... TEventArgs>
    struct Observable
    {
        void subscribe(Observer<TSource, TEventArgs...> *observer)
        {
            observers_.insert(observer);
        }

        void unsubscribe(Observer<TSource, TEventArgs...> *observer) { observers_.erase(observer); }

    protected:
        void notify(TSource &source, TEventArgs... args)
        {
            for (auto &&observer : observers_)
                observer->update(static_cast<TSource &>(*this), std::move(args...));
        }

    private:
        std::set<Observer<TSource, TEventArgs...> *> observers_;
    };
}

namespace ver_2
{
    //////////////////////////////////////////////////////////////////////////////////////
    template <typename TSource, typename... TEventArgs>
    class Observer
    {
    public:
        virtual void update(TSource &, TEventArgs... args) = 0;
        virtual ~Observer() = default;
    };

    //////////////////////////////////////////////////////////////////////////////////////
    template <typename TSource, typename... TEventArgs>
    struct Observable
    {
        using ObserverPtr = std::shared_ptr<Observer<TSource, TEventArgs...>>;
        using ObserverWeakPtr = std::weak_ptr<Observer<TSource, TEventArgs...>>;

        void subscribe(ObserverWeakPtr observer)
        {
            observers_.insert(observer);
        }

        void unsubscribe(ObserverWeakPtr observer) { observers_.erase(observer); }

    protected:
        void notify(TSource &source, TEventArgs... args)
        {
            for (auto &&observer : observers_)
            {
                auto living_observer = observer.lock();
                if (living_observer)
                    living_observer->update(static_cast<TSource &>(*this), std::move(args...));
            }
        }

    private:
        std::set<ObserverWeakPtr, std::owner_less<ObserverWeakPtr>> observers_;
    };
}

#endif /*OBSERVER_HPP_*/
