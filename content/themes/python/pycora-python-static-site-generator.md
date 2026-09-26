---
layout: themes-detil.cax
title: New Pycora Python SSG
description: Python Static Site Generator. Built with Python, fast, minimal, and elegant - PYCORA.
image: python/pycora-python-ssg_rnzdsw.png
features:
 - Axcora
 - Axcora Zetta Core
 - Starter Project
 - Fast Website
 - Auto SEO
 - Fast Build
 - Jinja Templating
 - Font Awesome Icon
 - Bootstrap CSS
 - JSON Data
 - Yaml Data
 - Markdown Content
 - Python SSG
 - All Static Hosting support Vercel, Cloudflare, Netlify , Github Pages and others.
 - All PHP Hosting support Cpanel, Plesk, Direct Admin , VPS and others.
download: https://creativitaz.gumroad.com/l/pycora
demo: https://pycora.axcora.com/
tags:
  - themestemplate
  - website themes
  - website template
  - blog template
  - themes
  - template
  - pythonssg
  - freethemes
  - featuredthemes
  - pythonthemes
date: 2026-08-07
---
### Introduction

PyCora is a [python](https://www.python.org/) static site generator that converts Markdown files with YAML frontmatter into fully functional HTML websites.

If you need python SSG look like [jekyll](https://jekyllrb.com/) or [11ty](https://www.11ty.dev/) - pycora is the best choice for you !!

### Get Started

Need to install 
+ Python Download Python : https://www.python.org/downloads/
+ Optional pip (Python package manager)

Next we need to download this project

+ Download via gumroad https://creativitaz.gumroad.com/l/pycora
+ Download via github https://github.com/mesinkasir/pycora

Or clone this repo , open terminal and run this command 
```
git clone https://github.com/mesinkasir/pycora.git
```

### Installation

Open project folder then terminal and run this command.
```
git clone https://github.com/mesinkasir/pycora.git
cd pycora
python install.py
```

### Test Run Project

After installation you can run your project

Run build
```
python ssg.py
```

Dev mode
```
python dev.py
```

Run Python
```
python run.py
```

Or you can use node js npm
```
npm run build   # Build site
npm run dev     # Development server
npm run serve   # Serve output directory
npm run menu    # Menu interface
```

### Project Structures

Pycora python project structure
```
pycora/
├── content/
│   ├── posts/           # Blog posts (Markdown + YAML)
│   │   └── 2024-01-01-hello-world.md
│   └── pages/           # Static pages (Markdown + YAML)
│       └── about.md
├── templates/           # Jinja2 templates
│   ├── base.html        # Base layout
│   ├── landing.html     # Homepage
│   ├── blog.html        # Blog listing
│   ├── post.html        # Single post
│   ├── page.html        # Static page
│   ├── tags.html        # Tags index
│   ├── tag.html         # Tag detail
│   ├── 404.html         # 404 page
│   ├── feed.xml         # RSS feed
│   └── sitemap.xml      # Sitemap
├── static/              # Static assets
│   ├── css/
│   │   ├── bs.css
│   │   └── main.css
│   ├── js/
│   └── images/
├── output/              # Generated site (build output)
│   ├── index.html
│   ├── blog/
│   ├── tags/
│   ├── feed.xml
│   └── sitemap.xml
├── ssg.py               # Main builder
├── dev.py               # Development server
├── install.py           # Dependency installer
├── run.py               # Menu interface
├── config.yaml          # Site configuration
├── package.json         # NPM scripts
├── requirements.txt     # Python dependencies
└── README.md            # Documentation
```

### Website Configuration

For firs you can setup your site open on `config.yaml`
```
site:
  name: PyCora
  description: Static Site Generator with Python
  url: http://localhost:8000
  author: Your Name
  twitter_username: yourusername
  image: /static/images/og-image.jpg

  nav:
    list:
      - name: Home
        url: /
      - name: Blog
        url: /blog
      - name: About
        url: /about

  hero:
    title: Write
    sub_title: Content
    title2: in Markdown
    text: "Static Site Generator with Python - Fast, Minimal, Elegant."
    button1:
      text: Read blog
      url: /blog/
    button2:
      text: Learn More
      url: /about/
    terminal:
      title: Quick Start
      info: "Simple. Fast. Elegant."
      list:
        - text: "$ python ssg.py build"
        - text: "$ Building site..."
        - text: "$ Pycora is ready for Deploy !!"

  features:
    title: Why Choose PyCora?
    list:
      - icon: "fas fa-bolt text-primary"
        title: Lightning Fast
        text: "Pure static HTML. No database. No server-side processing."

  footer:
    list:
      - name: Github
        icon: fab fa-github
        url: https://github.com/yourusername
```

Change with your site configuration.

Site is for you site SEO , nav for update your navbar, hero to update your hero on home page, and others.

### Update Static Page

To update your static page eg: about and others, you can make CRUD , create , update and delete your static page on `content/pages`

implementation frontmatter format: 
```
---
title: About Me
description: Learn more about me
date: 2024-01-15
author: Your Name
layout: page
---

# About Me

This is the about page.
```

### Update Post Collections

If you want to update post artilce collections, access on `content/posts`

implementation frontmatter format: 
```
---
title: My First Post
description: A brief description of my post
date: 2024-01-15
author: Your Name
tags:
  - python
  - ssg
  - markdown
image: /images/post-image.jpg
layout: post
---

# Welcome to My Blog

This is my first post using PyCora.

## Why Static Sites?

- Fast - No database queries
- Secure - No vulnerabilities
- Simple - Write in Markdown

```

### Layouting

PyCora uses Jinja2 templates located in the templates/ directory:

+ base.html - Base layout with navbar, footer, SEO
+ landing.html - Homepage with hero and features
+ blog.html - Blog listing with pagination
+ post.html - Single post with author, tags, next/prev
+ page.html - Static page layout
+ tags.html - Tags index page
+ tag.html - Posts filtered by tag
+ 404.html - Custom 404 error page
+ feed.xml - RSS feed template
+ sitemap.xml - Sitemap template

### Deployment

Need to deploy in to your host, you can run
```
python ssg.py
```

and upload your `output` folder in to your hosting.

### Support Pycora

+ [Support via PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JVZVXBC4N9DAN)
+ [Support via Github](https://github.com/sponsors/mesinkasir)
+ [Support via Gumroad](https://creativitaz.gumroad.com/coffee)
