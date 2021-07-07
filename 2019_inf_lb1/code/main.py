import wikipedia
import help_wiki_function

def check_language(lang):
    if lang in wikipedia.languages().keys():
        wikipedia.set_lang(lang)
        return True
    else:
        return False


def max_summary(pages):
    max_sum = 0
    max_tab = ''

    for name in pages:
        tab = wikipedia.page(name)
        tab_sum = len(tab.summary.split())
        if tab_sum >= max_sum:
            max_sum = tab_sum
            max_tab = tab.title
    return str(max_sum) + ' ' + max_tab


def make_chain(pages):
    chain = [pages[0]]
    for i in range(len(pages)-1):
        tab = wikipedia.page(pages[i])
	if pages[i+1] in tab.links:
            chain.append(pages[i+1])
        else:
            for name in tab.links:
                if not help_wiki_function.is_page_valid(name):
                    continue
                elem = wikipedia.page(name)
                if pages[i+1] in elem.links:
                    chain.append(name)
                    chain.append(pages[i+1])
                    break
    return chain


user_in = input().split(', ')
if check_language(user_in[-1]):
    print(max_summary(user_in[0:-1]))
    print(make_chain(user_in[0:-1]))
else: print('no results')
