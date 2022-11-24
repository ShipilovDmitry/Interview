namespace my {

    template<typename ...Args>
    class function;

    template<typename Res, typename ...Args>
    class function<Res(Args...)> {
    private:
        struct Base {
            virtual Base *copy() = 0;

            virtual Res call(Args...) = 0;

            virtual ~Base() = default;
        };

        template<typename Functor>
        struct Derived : public Base {
            Functor f;

            Derived(const Functor &f) : f(f) {}

            Base *copy() override {
                new Derived<Functor>(f);
            }

            Res call(Args &&... args) override {
                return f(std::forward<Args>(args)...);
            }
        };

        std::aligned_storage<16> buf;
        Base *f;
    public:
        template<typename F>
        function(const F &f)
                : f(new Derived<F>(f)) {}

        ~function() {
            delete f;
        }

        function(const function &other)
                : f(other.f->copy()) {
        }

        Res operator()(Args...args) {
            return f->call(std::forward<Args>(args)...);
        }
    };
}