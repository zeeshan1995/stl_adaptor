
#include <algorithm>


namespace stl_adaptor
{
    template<typename InputIterator
            ,typename ValueType>
    InputIterator find_nth(InputIterator         first
                          ,InputIterator         last
                          ,ValueType     const & value
                          ,std::size_t           nth)
    {
        if( not nth )
            return last;

        while( first != last and nth)
        {
            first = std::find(first, last, value);
            --nth;
            if( nth and first != last )
                first = std::next(first);
        }
        return first;
    }

    template<typename InputIterator
            ,typename ValueType>
    auto find_nth(InputIterator         first
                 ,std::size_t           count
                 ,ValueType     const & value
                 ,std::size_t           nth)
        ->std::pair<InputIterator, std::size_t>
    {
        if( not nth )
            return {first, 0};

        while( count and nth)
        {
            if ( *first == value )
                --nth;
            if( nth )
            {
                --count;
                first = std::next(first);
            }
        }
        return {first, count};
    }
}
