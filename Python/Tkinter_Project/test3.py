from tkinter import *

root = Tk()
root.geometry('720x480')
frame1 = Frame(root, background='blue', borderwidth=1)
frame1.pack()
label1 = Label(frame1, text='hi')
label1.pack()
root.mainloop()
