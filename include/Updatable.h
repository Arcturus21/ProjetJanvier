#ifndef UPDATABLE_H
#define UPDATABLE_H


class Updatable
{
    public:
        Updatable(bool active=true);
        virtual ~Updatable();

        virtual void Update(float elapsedTime)=0;

        void SetActive(bool active){_active=active;};
        bool IsActive() const {return _active;};

    protected:

    private:
        bool _active;
};

#endif // UPDATABLE_H
