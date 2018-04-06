原子的创建最后会由一个字符串来当做键值


//返回原子中字符串的长度
S32 my_atom_length(const S8 *ps8Str);

//创建一个新的原子并返回原子的字符串
S8 *my_atom_new(const S8 *ps8Str, S32 s32Len);

//传递一个字符串来创建一个原子
S8 *my_atom_string(const S8 *ps8Str);

//传递一个整数来创建一个原子
S8 *my_atom_init(S32 s32Num);
