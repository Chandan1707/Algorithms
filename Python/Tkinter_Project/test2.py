from tkinter import *

root = Tk()
root.geometry('720x480')
frame1 = Frame(root)
frame1.grid(row=0, column=0)
label1 = Label(frame1, text='Name :').grid(row=0, column=0)
entry1 = Entry(frame1).grid(row=0, column=1)
label2 = Label(frame1, text='roll :').grid(row=1, column=0, sticky='w')
entry2 = Entry(frame1).grid(row=1, column=1)
root.mainloop()
