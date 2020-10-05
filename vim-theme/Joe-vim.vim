" Author: NimComPoo-04
" Version: LMAO
" Lisense: i coppied this from vim built in theme industry so u do u want ok
" ;->
" This theme is made my me and it is wierd
" I tried to make it look like the joe editor
" it kind of is but it is much more wierd than you think

set background=dark
highlight clear
if exists("syntax_on")
    syntax reset
endif

let colors_name = "jthingy"

" First set Normal to regular white on black text colors:
hi Normal ctermfg=LightGray ctermbg=Black 

" Syntax highlighting (other color-groups using default, see :help group-name):

hi Comment	cterm=NONE ctermfg=DarkRed
hi String	cterm=NONE ctermfg=darkgreen
hi Number	cterm=NONE ctermfg=blue
hi Float	cterm=NONE ctermfg=darkmagenta
hi Character	cterm=NONE ctermfg=lightgreen

hi Function	cterm=NONE ctermfg=darkyellow


hi Statement	cterm=NONE ctermfg=white
hi Operator	cterm=NONE ctermfg=DarkCyan

hi Include	cterm=NONE ctermfg=DarkBlue
hi Define	cterm=NONE ctermfg=darkcyan
hi PreCondit	cterm=NONE ctermfg=cyan

hi StorageClass	cterm=NONE ctermfg=darkyellow
hi Structure	cterm=NONE ctermfg=yellow
hi Typedef	cterm=NONE ctermfg=lightred

hi SpecialComment cterm=NONE ctermfg=lightred
hi Type		cterm=NONE ctermfg=white
