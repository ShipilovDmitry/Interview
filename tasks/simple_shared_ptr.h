namespace ptr {

template <typename T>
class shared_ptr {
public:
    shared_ptr(T * ptr)
        : m_ptr(ptr)
        , m_count(new size_t(1)) {}

    shared_ptr(T const & other) noexcept
        : m_ptr(other.m_ptr)
        , m_count(other.m_count) {
            ++*m_count;
        }
    
    shared_ptr(T && other) noexcept
        : m_ptr(other.m_ptr)
        , m_count(other.m_count) {
            other.m_ptr = nullptr;
            other.m_count = nullptr;
        }

    ~shared_ptr() {
        if (!count) {
            return;
        }

        if (--*m_count == 0) {
            delete m_ptr;
            delete m_count;
        }
    }

private:
    T * m_ptr{nullptr};
    size_t * m_count{nullptr};
};
}
