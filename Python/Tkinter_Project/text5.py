from tkinter import *
root = Tk()
width = 720
height = 480
root.geometry(f'{width}x{height}')
main_menu = Menu(root)
sub_menu_1 = Menu(main_menu)

sub_menu_12 = Menu(sub_menu_1)
sub_menu_12.add_command(label='c1')
sub_menu_12.add_command(label='c2')
sub_menu_12.add_command(label='c3')

sub_menu_1.add_command(label='New Project...')
sub_menu_1.add_command(label='New...')
sub_menu_1.add_command(label='Open...')
sub_menu_1.add_command(label='Save')
sub_menu_1.add_cascade(label='Save As...', menu=sub_menu_12)

main_menu.add_cascade(label='File', menu=sub_menu_1)

sub_menu_2 = Menu(main_menu, tearoff=0)
sub_menu_2.add_command(label='cut')
sub_menu_2.add_command(label='copy')
sub_menu_2.add_command(label='paste')

main_menu.add_cascade(menu=sub_menu_2, label='Edit')
root.config(menu=main_menu)
root.mainloop()
