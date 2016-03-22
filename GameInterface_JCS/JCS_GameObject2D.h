#ifndef __JCS_GAMEOBJECT2D_H__
#define __JCS_GAMEOBJECT2D_H__


namespace JCS_GameInterface
{
    class JCS_GameObject2D
    {
    public:
        virtual ~JCS_GameObject2D() { }

        virtual void Initialize() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };

}

typedef JCS_GameInterface::JCS_GameObject2D JCS_GameObject2D;

#endif // __JCS_GAMEOBJECT2D_H__

