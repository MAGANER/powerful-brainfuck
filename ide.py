from tkinter import *
from tkinter import filedialog

window = Tk()
window.title("PBF ide v 1.0")
window.geometry("480x360")


def save(event):
    script= filedialog.asksaveasfilename()
    path_to_s = script
    file = open(script,'w')
    code =  text_field.get(1.0,END)
    file.write(code)
    file.close()
    run_mode = open('sys2.spbf','w')
    run_mode.write(script)
    run_mode.close()
    run_mode = open('sys2.spbf','w')
    run_mode.write(path_to_s)
    run_mode.close()

def dopen(event):
    script= filedialog.askopenfilename()
    path_to_s = script
    file = open(script,'r')
    code =  file.read()
    text_field.insert(1.0,code)
    window.title(script)
    file.close()
    run_mode = open('sys2.spbf','w')
    run_mode.write(path_to_s)
    run_mode.close()

def new(event):
    window.title("shit.pbf")
    text_field.delete(1.0,END)
def run(event):
    file = open('sys.spbf','w')
    file.write('r')

new_s = Button(window,text='new')
new_s.bind("<Button-1>",new)
new_s.pack()

save_s = Button(window,text='save')
save_s.bind("<Button-1>",save)
save_s.pack()

open_s = Button(window,text='open')
open_s.bind("<Button-1>",dopen)
open_s.pack()

run_s = Button(window,text='run')
run_s.bind("<Button-1>",run)
run_s.pack()

text_field = Text()
text_field.pack()


window.mainloop()
