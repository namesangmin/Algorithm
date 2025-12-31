_,s=open(0,'rb')
print('NYOE S'[4*'1'in''.join(['01'[abs(i-j)==1]for i,j in zip(s,s[1:])])::2])