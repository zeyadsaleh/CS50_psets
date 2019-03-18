import cs50
import re
from flask import Flask, abort, redirect, render_template, request
from html import escape
from werkzeug.exceptions import default_exceptions, HTTPException

s = "helloZeyadSaleh"
k = 0
m = 4
subs = []
for i in range (len(s)):
    subs.append((s[k:(k + m)]))
    k = k + 1
    if((k + m) > len(s)):
        break
print(subs)

print(subs.clear)

