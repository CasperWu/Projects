class Resource
{
public:
    Manager* manager;
    Array<Employee*> employees;
    Mutex mutex;
    Resource();
    ~Resource();
};
