---
layout: themes-detil.cax
title: DOCKAR - Documentation Eleventy Themes
description: Free and open source code eleventy 11ty docs themes for help you build and develope documentation website projects
image: eleventy/eleventydocumentationsite_mo3en2.avif
features:
 - JAMSTACK
 - Node JS
 - Eleventy 11TY
 - Documentation Project
 - Easy Installation
 - Simple Clean Minimalist
 - Complete Features
 - Pagefind Search Functional
 - Eleventy Navigation
 - Eleventy Pagination
 - Eleventy Youtube Lite
 - ELeventy Image
 - Modern static host support for svelte frontend like netlify vercel cloudflare pages cloudcannon and others.
 - Documentation Ready
 - Full Source Code Themes Template Project
download: https://creativitaz.gumroad.com/l/dockar
demo: https://dockar.axcora.com
tags:
  - themestemplate
  - website themes
  - website template
  - docs themes
  - docs template
  - 11ty
  - frontend
  - cms
  - themes
  - template
  - blog
  - pagefind
  - eleventy
  - docthemes
  - 11tythemes
  - jamstackthemes
  - eleventythemes
  - freethemes
date: 2024-09-20
---

### About Dockar Documentation Projects

This project is created to help you build a complete, easy and fast documentation project site. run on [eleventy](https://www.11ty.dev/) make your site super fast.

Dockar full complete features

+ Eleventy Navigation to group your document articles
+ Eleventy Image automatically compresses your images
+ Eleventy Youtube Lite makes your videos fast and light
+ Pagefind for your search function
+ Home page with JSON / JS data
+ Static Page
+ Dynamic Page
+ Documentation List
+ Documentation Article
+ Blog List
+ Blog Post Artilce
+ And More...

https://www.youtube.com/watch?v=ACIhddCkgtk

### Installation

+ Download Source Code Project
+ Download and Install Node JS
+ Create new project folder and extract all source code files in to your new project folder.
+ Access your new project using terminal
+ Run installation `npm install && npm start`
+ Open web browser `localhost:8080`
+ Configuration your website in `_data/metadata.js`
+ For Create or update documentation page access on `content/docs` folder
+ For Add new or update blog post article access on `content/blog` folder
+ Update content article in `content` folder - then create your article.md files, and insert fontformatter. Or you can copy paste from example article, and edit with you needed.
+ For build production mode you can run `npm run build` and upload your _site folder.
+ For push on github, you need to create github account , then create new repo, and push your source code project in to your github repo.

### Site Configuration

For first you need to setup your site, open on `_data/metadata.js`

Note: Upload your favicon and image logo in to `content/media` folder, next you can simply add your image in to configuration data. implementation `image: /media/myimage.png`

Next you can update your site , such navigation, and others.

#### SEO Setup

Change your title description and url site in to this line code

```js
	title: "Your title in here...",
	url: "Insert your domain url",
	language: "en",
	description: "Description about your docs site here...",
	image: "Your image in here...",
	favicon: "/media/img/dockarlogo.png",
```

Next you can save to update your setup.

#### Widget Area

Dockar is supported by default with widgets, such as social media icons, display footer area, and more. You can customize it to your needs.

```js
    show_social_icon: true, // change false if you do not want to show social icon navbar
    show_footer: false, // change false if you do not want to show footer
    show_search: true, // change false if you do not want to show search widget
```

You can change `false` to disable widget or change to be `true` if you want enable the widget.

#### Search Widget Pagefind

Scroll down and found this line code, you can change nav and modal title for your search menu.

```js
    search_widget: {
                        nav_title: "Change Text for your placeholder search widget here...",
                        modal_title: "Change text for your modal search title in here..."
                    },
```

Save it to update your search widget.

#### Github Colaborator

Dockar allows you to create collaboration for your project, first you need to add your github repo project. To use this feature you need to enable it on your document page for collaboration.

Add your github project repo on this line code

```js
    github_project: {
                        repo: "https://github.com/user/yourrepo",
                        branch: "add your repo branch here.."
                    },
```

Insert your github repo url link, and select your main branch.

#### Navigation

To change your navbar menu you can found this line code.

```js
	nav: 
          [
            {
        		name: "Home",
		        link: "/"
	         },
            {
        		name: "About",
		        link: "/about/"
	         },
            {
        		name: "your navbar title...",
		        link: "insert url page link here.."
	         }
        ],
```

Update nav name and link url with your needs.

#### Social Media

You can add your social media on this [documentation site project]({{page.url}})

Found this line code

```js
	social:
            [
             {
        		title: "Github Repo",
        		icon: "github",
		        link: "https://www.github.com/mesinkasir/dockar"
	         },
             {
        		title: "Visit Main Site",
        		icon: "rocket-takeoff",
		        link: "https://captaline.pages.dev/"
	         },
           ],
```

Change icon with bootstrap icon and change link with your social media url link.

#### Footer Menu

If you activate footer widget area, next you can setup your footer area , srcoll down on `_data/metadata.js`, and found this line code.

```js
	footer:
            [
             {
        		title: "Get Start",
        		nav: [
                        { 
                            name: "Download",
                            link: "/doc/getstart/download/"
                        },
                        { 
                            name: "Installation",
                            link: "/doc/getstart/install/"
                        },
                        { 
                            name: "Run Project",
                            link: "/doc/runproject/"
                        }
                     ]
	         },
             {
        		title: "New menu title here...",
        		nav: [
                        { 
                            name: "Footer nav menu title here...",
                            link: "Insert url link here...."
                        },
                        { 
                            name: "Footer 2 nav menu title here...",
                            link: "Insert url link here...."
                        },
                        { 
                            name: "Footer 3 nav menu title here...",
                            link: "Insert url link here...."
                        }
                     ]
	         },
```

Next update and save it.

----

### Image and Media

Because we use eleventy images to automatically optimize your images,, For image and media files you can upload on `media` folder, next you can insert your image in to your documentation page.

Example Implementation on Cover Image

```YAML
image: /media/myimage.jpg
```

Example Implementation in to blog posts markdown file


```YAML
![my poto]()/media/myimage.jpg)
```

----

### Youtube Embed

This project is ready with youtube lite.

To embed a YouTube video into any Markdown page, paste its URL into a new line. The URL should be the only thing on that line.

```YAML
youtube.com/watch?v=dQw4w9WgXcQ

www.youtube.com/watch?v=dQw4w9WgXcQ

http://www.youtube.com/watch?v=dQw4w9WgXcQ

https://www.youtube.com/watch?v=dQw4w9WgXcQ

https://www.youtube.com/watch?v=dQw4w9WgXcQ

https://youtube.com/watch?v=dQw4w9WgXcQ

https://youtu.be/dQw4w9WgXcQ

https://www.youtube.com/watch?v=LQaehcfXvK0&feature=youtu.be

https://www.youtube.com/watch?v=dQw4w9WgXcQ&list=RDdQw4w9WgXcQ&start_radio=1&t=1
```

----

### Static Page

Dockar allows you to create new static pages, which you can use to create about pages, privacy policy pages and more as per your requirement. Open on `content/pages` and update or create new static page here.

frontmatter implementation

```YML
---
title: Your title here...
description: Your Description goes here....
permalink: You can set your custom url link here...
image: Your media file here....
---
Write content article on this area
```

If you want to create new page, you can simply create new markdown files, for example `about.md` , next you can write content articles

----

### Documentation Page

For documentation articles you can access them in the `content/docs` folder, then you can create new folders to group your documentation sites, or use markdown files.

Documentation article frontmatter implementation

```YML
---
title: Get Started Page
description: How to use documentation page on dockar 11ty eleventy docs site project
eleventyNavigation:
  key: Get Started
  order: 3
author:
 name: ELEVENTY DEV
 link: https://www.hockeycomputindo.com/en/jamstack/11ty
show_author: true
show_update_date: true
show_edit_page: true
show_table_of_content: false
update_date: 2024-08-16
tags:
  - docpage
---
```

The eleventy navigation is used to sort your documentation articles, An example of a key is the title for sidebar documentation, and order is the sequence number of your documentation article.

How to use sub or grouping of doc articles?

To group your document articles you can use the `parent` in your eleventy navigation

Code example

```yml
---
title: INstallation
description: How to install thisproject.
image: /media/img/docpage.png
eleventyNavigation:
  key: Installation
  parent: Get Started
  order: 1
update_date: 2024-09-10
author:
 name: JAMSTACK DEV
 link: https://www.hockeycomputindo.com/en/jamstack
show_author: true
show_update_date: true
show_edit_page: true
show_table_of_content: true
tags:
  - installation
---

Write article here...
```

In your sidebar documentation article, `Get Started` is in the group under `Installation`

----

### Blog Article

To create and update blog post articles, you can access them at `content/blog`

Frontmatter Code

```yml
---
title: Your title here...
description: Your description here....
date: 2024-08-17
image: /media/img/jamstackthemes.jpg
show_table_of_content: true
show_tag_cloud: true
show_update_post: true
author: creativitas.dev
tags:
 - this is tags
 - tags 1
---

Write Article in here....
```

You simply create a new blog article, simply create a new markdown file and write your content article.
