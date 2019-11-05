from os import system
lt={'1':'stack','2':'queue','3':'linkedlist','4':'bintree','5':'bstree','6':'sorts','7':'fix'}
name={'1':'Stack','2':'Queue','3':'Linked List','4':'Binary Tree','5':'Binary Search Tree',\
'6':'Sortings','7':'Infix Postfix'}
while True:
    system("clear")
    print "\t"+"-"*34
    print '\t|'+"::MENU::".center(32)+'|'
    print '\t|'+"1.Stack".ljust(32)+'|'
    print '\t|'+"2.Queue".ljust(32)+'|'
    print '\t|'+"3.Linked List".ljust(32)+'|'
    print '\t|'+"4.Binary Tree".ljust(32)+'|'
    print '\t|'+"5.Binary Search tree".ljust(32)+'|'
    print '\t|'+"6.Sortings".ljust(32)+'|'
    print '\t|'+"7.Infix Postfix".ljust(32)+'|'
    print '\t|'+"8.Exit".ljust(32)+'|'
    print "\t"+"-"*34
    ch = raw_input("\nEnter Choice: ")
    print
    if ch=='8': break
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
    else: print "Invalid Choice"
    raw_input("\nPress Enter to Continue...")
print "\t\t-----X-----\n"
