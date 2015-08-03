namespace kstdlib
{
    class AService : public AFactoryInterface
    {
    public:
    private:
    };

    inline void AService::setValue(int value) // définition en dehors de la classe (inline)
    {
        this->value = value;
    }

    void AService::print() const // définition en dehors de la classe (non inline)
    {
        std::cout << "Value=" << this->value << std::endl;
    }
} // kstdlib
