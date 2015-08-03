#ifndef IENGINE_H_
#define IENGINE_H_

class IEngine 
{
  public:
    	IEngine();
    	virtual ~IEngine();

      virtual bool run()=0;
      virtual bool drop()=0;

      virtual bool start()=0;
      virtual bool exit()=0;

      /**
       * détermination des connections avec les autres engines.
       */
      virtual bool connect()=0;


      virtual bool frame()=0;

      virtual bool isActive()=0;

      virtual void print()=0;
};

#endif /* IENGINE_H_ */

