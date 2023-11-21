//整型数据可变环-分辨率-2023年11月9日
//目前适用于圈数为正数

#define MAXNUM 0xffffffff
#define CYCLERATE 400
#define CWLVALUE    (MAXNUM - CYCLERATE + 1)
#define CWBVALUE    (CYCLERATE - 1)

unsigned int  VariableRotary(unsigned int actulpos)
{
    static unsigned int  lastpos = 0;
    static unsigned int  add = 0;
    unsigned int modvalue =  MAXNUM % CYCLERATE + 1;
    unsigned int repos = 0;

    //检测到正转溢出
    if((actulpos < lastpos ) && (actulpos < CWLVALUE && lastpos > CWBVALUE))
    {
        add += modvalue;
        ps_debugout("+++%d-%d add%d-%d\r\n",lastpos,actulpos,add,modvalue);
    }
    else if((actulpos > lastpos ) && (actulpos > CWBVALUE && lastpos < CWLVALUE))   //检测到反向溢出
    {
        add -= modvalue;
        ps_debugout("---%d-%d add%d-%d\r\n",lastpos,actulpos,add,modvalue);
    }
    if(lastpos != actulpos)
    {
    	lastpos = actulpos;
    }
    add = add % CYCLERATE;
    repos = ((actulpos % CYCLERATE) + add) % CYCLERATE;

    return repos;
}

