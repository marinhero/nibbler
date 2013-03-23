//
// GraphicFactory.cpp for nibbler in /home/ignatiev/Projects/nibbler
//
// Made by ivan ignatiev
// Login   <ignati_i@epitech.net>
//
// Started on  Fri Mar 22 19:57:26 2013 ivan ignatiev
// Last update Sat Mar 23 16:27:00 2013 ivan ignatiev
//

#include "GraphicFactory.hh"

GraphicFactory::GraphicFactory()
    : dl_handle_(NULL) , lf_(NULL), ulf_(NULL)
{
}

GraphicFactory::GraphicFactory(GraphicFactory const &gf)
{
    (void) gf;
}

GraphicFactory &GraphicFactory::operator=(GraphicFactory const &gf)
{
    (void) gf;
    return (*this);
}

GraphicFactory::~GraphicFactory()
{
}

AGraphic *GraphicFactory::load(const char *filename, Game *game)
{
    if (this->dl_handle_ != NULL)
    {
        std::cerr << "Error : library already loaded" << std::endl;
        // TODO : throw
        return (NULL);
    }
    if ((this->dl_handle_ = dlopen(filename, RTLD_LAZY | RTLD_GLOBAL)) != NULL)
    {
        this->lf_ = (load_func_t)(dlsym(this->dl_handle_, LOAD_FUNC_SYM));
        this->ulf_ = (unload_func_t)(dlsym(this->dl_handle_, UNLOAD_FUNC_SYM));
        if (this->lf_ && this->ulf_)
        {
            return (this->lf_(game));
        } else {
            std::cerr << "Error : symbols not found : " << dlerror() << std::endl;
        }
    } else {
        std::cerr << "Error : library not loaded : " << dlerror()  << std::endl;
    }
    // TODO : throw
    return (NULL);
}

void    GraphicFactory::unload(AGraphic *glib)
{
    if (this->dl_handle_ == NULL)
        // throw
        return ;
    this->ulf_(glib);
    dlclose(this->dl_handle_);
}
