#ifndef CURSOR_SERVICE_H
#define CURSOR_SERVICE_H

#include "CursorEntity.h"
#include "ICursorService.h"

namespace graphique
{
    class CursorService : public ICursorService
    {
        protected:
            ICursorService* thisInstance;

        public:
            CursorService(){
                this->thisInstance = this;
            };
            ~CursorService(){};
    };
} // business

#endif



