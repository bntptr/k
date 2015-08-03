namespace kstdlib
{
    class AMapperInterface : public MapperInterface
    {
    public:
    virtual loadById(int id);
    virtual exists(int id);
    virtual save(AEntity *entity);
    private:
    };
} // kstdlib
