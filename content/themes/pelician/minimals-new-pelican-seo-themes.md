---
layout: themes-detil.cax
title: Minimals Pelican SEO
description: Free download themes template pelican minimalist and clean with auto SEO support.
image: python/minimals_ib24xv.jpg
features:
 - Python Lang
 - Pelican Technology
 - Static Site Generator
 - Markdown Support
 - Auto SEO Injection
 - Sitemap Ready
 - Robots.txt Ready
 - Production Build Host
 - Documentation Ready
 - Full Source Code Themes Template Project
download: https://creativitaz.gumroad.com/l/minimals-pelican
demo: https://www.hockeycomputindo.com/dokumentasi/programtokomurah/
tags:
  - themestemplate
  - website themes
  - website template
  - blog themes
  - blog template
  - themes
  - template
  - blog
  - cms
  - backend
  - frontend
  - clean
  - minimalist
  - unique
  - python
  - pelican
  - pythonthemes
  - pelicanthemes
  - jamstackthemes
  - freethemes
---

Let's develope your modern website with JAMSTACK python technology, [pelician](https://getpelican.com/) static site generator.

## Installation

Before start with this project you need to install python and pelican static site generator.

### Install Python

First you need to download and install python in to your devices, how to install python in to mac , windows or linux you can read [python documentation](https://www.python.org/downloads/),you can skip this step if you have install python in to your device.

### Install PIP

Afer download and install python , now we need to install PIP too.. , how to install pip you can read [pip documentation](https://pip.pypa.io/en/stable/installation/) , you can skip this step if you have install PIP in to your device.

### Install Virtual Env

And yess... now we need to install vitrualvenv in to your devices, you can read [how to install venv](https://virtualenv.pypa.io/en/latest/installation.html) here , you can skip this step if you have install venv in to your device.

### Install Pelican

Now you can install pelican we have two options, first for new installation setup, and second if you have pelican project ready , so you just need to install the minimals themes in to your project.

#### New Installation

The next step we need to install pelican in to your device, so you can follow [how to install pelican here](https://docs.getpelican.com/en/latest/index.html)

Or if you use windows os you can follow this step 

Open terminal or CMD and run `py -m pip install "pelican[markdown]"`

Next we need to create virtualenv in to your python pelican project so you can run this command

```
virtualenv ~/virtualenvs/pelican
cd ~/virtualenvs/pelican
source bin/activate
```

Alternative if you have create venv for your python pelican, you can easy to run `venv\Scripts\activate` in to your python pelican installer location.

#### Themes Installation

Quick Start

+ create venv on pelican project and activate
+ download source code minimals pelican
+ create new folder name it with `themes` on your project folder
+ upload minimals to themes folder or run `git clone https://github.com/mesinkasir/minimals-pl.git`
+ open pelicanconf.py on your pelican project folder
+ insert `THEME = 'themes/minimals'` on `pelicanconf.py` , or open from source code`pelicanconf.py` from minimals/static/example-content` and copy all in to your project.

After you have activate venv for your python pelican project, next we need to install minimals themes.

Access your `venv` folder with terminal, and access your pelican themes folder on `venv\Lib\site-packages\pelican\themes` create new folder name it with `minimals` next you can download minimals pelican themes - open `zip` files, and extract copay all files in to the `minimals` folder , complete folder themes project location `venv\Lib\site-packages\pelican\themes\minimals`

#### Download and Install from github repo

Alternative you can clone from our github repo, for first access on `venv/pelican/themes` next you can easy run clone form github `git clone https://github.com/mesinkasir/minimals-pl.git`

After you have clone the repo, now you can rename from minmals-pl to minimals folder.

## Activate Minimals Themes

Ok, after you have install python, pip, venv, and pelican , now it's time to manage your project, for first open your minimals pelican themes on `minimals` folder, next step you can open the `static` folder, what you need is copy `pelicanconf.py` in to your site project.

### Switch Pelican Themes

Now we need to switch default pelican themes and activate your minimals themes open `pelicanconf.py` with code editor, and you can switch from default themes to be minimals.

Change on this line code

```
THEME = 'themes/minimals'
```

and save it.

### Test Run Minimals Themes

now we can try to run this themes with run `pelican content` after that run `pelican --autoreload --listen` and open `localhost:8000`

Congratulations, you have activate the [minimals new pelican themes]({{page.url}})

## Setup Your Site

Now we need to setup your site, so let's get started !!

open `pelicanconf.py` and customise with your needs.

### Configuration and SEO Pelican Website Project

We need to add the domain name ,author and setup your SEO, you can change on this line code.

```
AUTHOR = 'your author here..'
SITENAME = 'Your website title in here..'
SITEURL = "insert your domain name here.."
FAVICON = 'add url link for your favicon image here..'
SITESUBTITLE = 'Description for SEO your site here..'
```

Implementation

```
AUTHOR = 'creativitas'
SITENAME = 'Minimalis Pelican Themes'
SITEURL = "https://www.hockeycomputindo.com/dokumentasi/programtokomurah/"
FAVICON = '/static/images/pelican.png'
SITESUBTITLE = 'A minimalis themes for python pelican static site generator project'
```

### Header and Navbar

For update your navbar and webiste slogan + navigation menu, you can change on this line code.

```
SITESLOGAN = 'Your site slogan here..'
SITE_INTRO = 'Your header intro text  here..'
MENUITEMS = (
    ("Your menu 1 name..", "Insert url for your menu 1 link here.."),
    ("Your menu 2 name..", "Insert url for your menu 2 link here.."),
    ("Your menu 3 name..", "Insert url for your menu 3 link here.."),
    ("Your menu 4 name..", "Insert url for your menu 4 link here.."),
)
```

Implementation

```
SITESLOGAN = 'Minimals'
SITE_INTRO = 'Clean Minimalist and SEO themes for Pelician Project'
MENUITEMS = (
    ("Home", "/"),
    ("Page", "/pages/static-page.html"),
    ("Posts", "/archives.html"),
    ("Contact", "/pages/contact-us.html"),
)
```

### Footer Area

Now for update footer area you can change this line code

```
FOOTER_AREA = (
    ("Your footer 1 goes here...."),
    ("Your footer 2 goes here...."),
)
```

Implementation

```
FOOTER_AREA = (
    ("Clean Minimalist Pelican Themes Project - Develope by Creativitas - https://creativitas.dev"),
    ("Hire developer on fiverr - https://fiverr.com/creativitas"),
)
```

### Post Display

Next you can change the number of post display on this line code.

```
DEFAULT_PAGINATION = 4
```

just change with the number you want to display your lastest blog posts, and save it.

## Folder Structure

The folder structure for [minimals new pelican themes]({{page.url}}) look like this

### Static Folder

Static folder is for your media assets such image, pdf files and others, you can uplad image and all your files in to this folder. for use this static assets you can simply put `/static/image/myphoto.jpg` on your frontmatter markdown post.

### Pages Folder

You need to create pages folder, this folder is using for your static page. For example for your about or contact page.

### Posts Folder

For posts article you can use inside content folder, or create new folder for your blog posts article.

## Writing Content

### Pages Article

You can create new folder and name it with `pages` then access on `content/pages` and write your statci page content in this folder.

#### Create new Static Page

For create new article you can simply create new .md files, and name it with your own, for example `myblogpost.md` and write your article.

#### Update Static Page

If you need to update or edit your article you can open your article and change with you needs.

#### Delete Static Page

For delete posts article you can simply delete .md files.

#### Frontmatter Static Page

frontmatter markdown concept for static page look like this

```
Title: Your page title here...
Date: Insert publih date here...
Description: Your intro header for static page in here...
Summary: Your description for static page in here...

Write your content in here...

```

Implementation

```
Title: Contact Us
Date: 2024-02-03 10:20
Description: This is contact description on header
Summary: Contact description for SEO meta tag

# Creativitas Developer

Site: https://creativitas.dev

Hire Developer on Fiverr: https://fiverr.com/creativitas

```

### Posts Article

You can access on `content` or create new folder `posts` and write your content in this folder.

#### Create new posts article

For create new article you can simply create new .md files, and name it with your own, for example `myblogpost.md` and write your article.

#### Update posts article

If you need to update or edit your article you can open your article and change with you needs.

#### Delete posts article

For delete posts article you can simply delete .md files.

#### Markdown Posts Format

Frontmatter markdown format for posts article.

```
Title: Title goes here..
Image: URL or CDN image for cover in here..
Date: Add publih date in here..
Category: Insert Category in here..
Tags: insert all your tags with coma in here..
Authors: Your Author in here..
Summary: Description for SEO in here..
Description: Description for header area in here...

Write your article in here...

```

Implementation

```
Title: Delpaos
Image: https://images.unsplash.com/photo-1588345921523-c2dcdb7f1dcd?w=500&auto=format&fit=crop&q=60&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxzZWFyY2h8Mnx8d2hpdGV8ZW58MHwwfDB8fHww
Date: 2024-05-27 12:20
Category: Lorep
Tags: post1, hello, world, ipsum
Authors: Creativitas
Summary: Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo.
Description: Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo.

### Sed Ut Perspiciatis

Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam es

```

## CLI Command

After you have create static page and update your site project, next you can run and test on your devices.

### First Build for Production

For first we need to build production mode for your site , open terminal and run `pelican content`

### Run Dev Mode

Next you can run your project , open terminal and run `pelican --listen` , of you need live reload so you can run this command `pelican --autoreload --listen` and access on `localhost:8000` your web browser

### Build Production

If you want upload to your host or deploy it, you can build for production mode , open terminal and run `pelican content`

## Upload On Hosting

Next step you can upload on your own hosting for make your site live.

### All Hosting

just upload the `output` the build production folder in to your host.

### Github Pages Host

For github pages host, you need to create `workflow.yml` files , you can read [how to run pelican on github pages here](https://docs.getpelican.com/en/latest/tips.html#publishing-to-github-pages).

And thank you by using our source code project, we hope this project can help you for build Python JAMSTACK website fast secure and SEO.

Support Us - You can support us for buy me a cup of coffee. just click donate button on top pages.
