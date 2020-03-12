# f = open("smaple.txt","w")
# f.write("OK")
# f.close()

# class open_fiLe(object):
#     """docstring for open_fiLe."""
#
#     def __init__(self, filename,mode):
#         # super(open_fiLe, self).__init__()
#         self.filename = filename
#         self.mode = mode
#
#     def __enter__(self):
#         self.file = open(self.filename,self.mode)
#         return self.file
#
#         pass
#     def __exit__(self,exc_type,exc_val,tracebak):
#         self.file.close()
#         #throw a exception
#         pass
#
# with open_fiLe('smaple.txt','w') as f:
#     f.write("Testing")
#
# print(f.closed)

from contextlib import contextmanager

# @contextmanager
# def open_fiLe(file,mode):
#     f = open(file,mode)
#     yield f
#     f.close()
#
#
# with open_fiLe('smaple.txt','w') as f:
#     f.write('Loren Ipsum dolor_sit_amae')
#
# print(f.closed)
