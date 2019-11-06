from os import system
lt={'2':'stack','3':'queue','1':'linkedlist','4':'bintree','5':'bstree','6':'sorts','7':'fix'}
name={'2':'Stack','3':'Queue','1':'Linked List','4':'Binary Tree','5':'Binary Search Tree',\
'6':'Sortings','7':'Infix Postfix','8':'Group Info','9':'Credits','10':'Exit'}
while True:
    system("clear")
    print "\t"+"-"*34
    print '\t|'+"::MENU::".center(32)+'|'
    for i in ['1','2','3','4','5','6','7','8','9','10']:
        print '\t|'+(' '*(2-len(i))+i+'.'+name[i]).ljust(32)+'|'
    print "\t"+"-"*34
    ch = raw_input("\nEnter Choice: ")
    print
    if ch=='10': break
    if ch in ['1','2','3','4','5','6','7'] and ch!='':
        system("clear")
        print "\t"+"-"*34
        print '\t|'+("::"+name[ch]+" Menu::").center(32)+'|'
        print '\t|'+"1.Compile".ljust(32)+'|'
        print '\t|'+"2.Run".ljust(32)+'|'
        print '\t|'+"3.Display Source Code".ljust(32)+'|'
        print '\t|'+"4.Back".ljust(32)+'|'
        print "\t"+"-"*34
        chx = raw_input("\nEnter Choice: ")
        print
        if chx=='1':
            system("gcc "+lt[ch]+".c -o "+lt[ch]+".out")
            print "Compiled!"
        elif chx=='2':
            system("./"+lt[ch]+".out")
        elif chx=='3':
            system("codium "+lt[ch]+".c")
    elif ch=='8':
        system("clear")
        print '\t'+"::Group Info::".center(32)
        print open("ginfo.txt",'r').read()
    elif ch=='9':
        system("clear")
        print '\t'+"::Credits::".center(32)
        print open("credits.txt",'r').read()
    else: print "Invalid Choice!"
    raw_input("\nPress Enter to Continue...")
print "\t\t-----X-----\n"
