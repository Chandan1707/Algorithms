from tkinter import *
import temp
length = 720
height = 480
root = Tk()
root.geometry(f'{length}x{height}')
Label(root, text='Wellcome', font='comicsansms 25 bold').grid(row=0, column=1)
Label(root, text='Name :').grid(row=1, column=0, sticky='w', ipadx=30)
Label(root, text='Phone :').grid(row=2, column=0, sticky='w', ipadx=30)
Label(root, text='Gender :').grid(row=3, column=0, sticky='w', ipadx=30)
Label(root, text='Payment Method :').grid(row=4, column=0, sticky='w', ipadx=30)

nameValue = StringVar()
phoneValue = StringVar()
genderValue = StringVar()
paymentValue = StringVar()
foodServiceValue = IntVar()
Checkbutton(root, text='Want to prebook meals ?', variable=foodServiceValue).grid(row=5, column=1)

Entry(root, textvariable=nameValue).grid(row=1, column=1)
Entry(root, textvariable=phoneValue).grid(row=2, column=1)
Entry(root, textvariable=genderValue).grid(row=3, column=1)
Entry(root, textvariable=paymentValue).grid(row=4, column=1)

Button(root, text='Submit', compound='left', command=temp.submit).grid(row=6, column=1, sticky='w')

root.mainloop()
