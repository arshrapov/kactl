"General editor settings
set tabstop=2
set nocompatible
set shiftwidth=2
set softtabstop=2
set expandtab
set smarttab
set autoindent
set smartindent
set ruler
set showcmd
set incsearch
set shellslash
set number
set relativenumber
set cino+=L0 
syntax on
filetype indent on
filetype off
setlocal indentkeys-=:

"colorscheme
colorscheme spacegray

"keybindings for { completion, "jk" for escape, ctrl-a to select all
imap jk         <Esc>
map <C-a> <esc>ggVG<CR>
set belloff=all

"Append template to new C++ files
autocmd BufNewFile *.cpp 0r /home/jayleeds/vimcp/Library/Template.cpp

"Compile and run
"Note that this line requires the build.sh script!
autocmd filetype cpp nnoremap <F9> :w <bar> !run.sh <CR> 
autocmd filetype cpp nnoremap <F10> :!./%:r<CR>
