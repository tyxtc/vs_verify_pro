#define MAXNUM UINT32_MAX
#define CYCLERATE 400
#define CWLVALUE    (UINT32_MAX - CYCLERATE + 1)
#define CWBVALUE    (CYCLERATE - 1)

unsigned int  VariableRotary(unsigned int actulpos)
{
    static int unsigned lastpos = 0;
    static int unsigned add = 0;
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
    repos = ((actulpos % CYCLERATE) + add) % CYCLERATE;

    return repos;
}

