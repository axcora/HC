---
layout: themes-detil.cax
title: Portfolio Web and UI Designer themes template
description: Free download and open source code JAMSTACK Portfolio for website developer and UI Designer themes template.
image: eleventy/portfolio_kplzcj.jpg
date: 2024-12-31
features:
 - Node JS
 - Js Lang
 - SEO Focus
 - Portfolio Themes
 - Eleventy 11ty
 - Decap Netlify CMS
 - JAMSTACK
 - Static Site Generator
 - Modern Host support netlify vercel cloudflare and others 
 - Build production host firebase surge cpanel vps direct admin plesk and others
download: https://creativitaz.gumroad.com/l/bharatkat
demo: https://bharatkat.axcora.com/
tags:
  - themestemplate
  - website themes
  - website template
  - blog themes
  - blog template
  - portfolio themes
  - portfolio template
  - web developer themes
  - web developer template
  - jamstack themes
  - jamstack template
  - eleventy
  - 11ty
  - themes
  - template
  - eleventythemes
  - jamstackthemes
  - freethemes
---

### Documentation

How to install and work with [BharatKat JAMSTACK portfolio YAL YAL website Themes]({{page.url}}) project.

#### Local Installation

+ Download and install [Node JS](https://nodejs.org/en/download/) on your devices
+ Download Source Code Project
+ Create New folder on desktop name it with your project.
+ Extract source code files in to your project 
+ Access with terminal run 'cd C:\Users\pcname\Desktop\yourproject' change pcname with your pc name and change yourproject with your new project.
+ Run Installation with Terminal `npm install && npm start`
+ Open localhost:8080
+ For stop , you can presh ctrl+C

#### Run and Install Decap CMS on Local

We need to open two terminal, one to run your project with `npm start` and second to run your backend decap netlify headless cms with `npx decap-server`

+ Open terminal and run `npm start`
+ Open new terminal and run `npx decap-server`
+ Access your frontend on `localhost:8080`
+ Access your backend headless cms on `localhost:8080/admin`

#### Work with Decap CMS

+ Login in to CMS
+ First we need to setup your site, access SEO setup and change with your needs here.
+ Next we can Update Navbar , access in to navbar menu and update it
+ Now you can update your widget in to widget area
+ Update your footer setup in footer area
+ And update your copyrights text in to copyrights area
+ Home Page for update your homepage area
+ Project List for update your project list page
+ Project article to create article for your projects
+ Blog List to update your blog list page.
+ Blog Post article to create your blog post article
+ Static pages to update and create new your static page, example about , contact and others.

https://www.youtube.com/watch?v=O__KMyIWBxA

#### Push On Github

+ Create account on [github](https://www.github.com/)
+ Create new repo and name it with your project + select add `README.md` file.
+ Create new folder 
+ Open terminal
+ And run this command `git clone https://github.com/username/yourrepo.git` - change username with your github user name and change yourrepo with your github repo project name.
+ After you have clone your github repo, now you can copy all source code project in to your new github repo folder.
+ Next you can access your github repo folder and terminal run `git add .` , next you can run `git commit -m "My portfolio website by creativitas"` and the end you can push your local source code in to your github repo by run this command `git push https://github.com/username/yourrepo.git` - change username with your github user name and change yourrepo with your github repo project name.

#### Make your website online

+ You can use [neltify](https://netlify.com) , vercel , cloudflare pages for deploy your eleventy website blog project - but on this projects is already integration with decap cms, so we recommended you use netlify for your host.
+ Create account with your github account on netlify , next you can create new website or projeect.
+ After you have create new project now you can integration your github repo, select your repo project, and select eleventy framework , then click deploy.
+ Congratulations your JAMSTACK website is live now !!

#### Activate Decap Cloud CMS

You need to advance setup , first login in to netlify with your account, next you can activate Netlify Identity

+ Open site Configuration
+ Select Identity Menu
+ On Registration preferences - select github , google and others.
+ The Last Activate Git Gateway
+ After you have configure your Setup now your Backend Headless Decap Cloud CMS is ready !!
+ Access yourdomain.com/admin and login with github or google account.

#### Production build for PHP Hosting

If you want to run on your PHP hosting like cpanel, plesk,direct admin , apanel , VPS and others. So you need to build production mode for your project. 

Run `npm run build` and upload your build production `_site` folder into your hosting.

But we recommended to you for use modern static hosting.

This project is ready with decap cms, so if you want run on PHP hosting , you can work on local with decap cms, after you have make update you can run build command `npm run build` and upload your build production folder `_site` in to your hosting.

---

## Advance for Developer

### Style

Styling on `public/style.css`

### Design Layout

Design Layout on `_includes/layout`

+ Base for base themes
+ Blog Post for post article
+ Blog for blog list article
+ Start for Home Page Layout

#### Home Design

Content article for data on `content/index.njk`

To customise design on `layouts/home`

+ Header for update header area
+ Hero for update hero area
+ Intro List for update intro list area
+ Intro for update intro area
+ section 1 for update section1 area
+ section 2 folder for update section 2 area
+ section 3 folder for update section 3 area
+ section 4 folder for update section 4 area
+ section 5 folder for update section 5 area
+ section 6 folder for update section 6 area
+ section 7 folder for update section 7 area

#### Blog List Design

Content article for data on `content/blog.njk`

+ Blog List for update blog list area
+ Header for update header area
+ Hero_image for update hero image area
+ Pagination for update pagination blog area

#### Post Article Design

Content article for data on `content/blog/` folder

+ Popular Post for update popular post area
+ Header for update header area
+ Hero_image for update hero image area
+ Pagination for update pagination article area

#### Post Article Design

Content article for data on `content/blog/` folder

+ Popular Post for update popular post area
+ Header for update header area
+ Hero_image for update hero image area
+ Pagination for update pagination article area

#### Base Design

Base is use for all pages folder `content/pages/` 

+ Content for update content article area
+ Header for update header area

### Widget

Widget is use for footer , navigation and others

+ Navbar folder for update navbar mobile and navbar desktop
+ Blog_slider for update blog slider on home page
+ Blog_list_ for update blog list article
+ Footer for Update footer area
+ Marquee for update marquee area
+ Post List use for tags design
+ SEO for inject auto SEO script
+ Style for add css files

### Content

Content is use for update article blog post, and static page

+ Index.njk is for udpate home page
+ Blog folder for your content blog article
+ Pages folder for static page , such about, contact , privacy policy and others.
+ Feed for generate your `feed.json` and `feed.xml` to boost up your SEO. 

### Configuration

File for setup your site

+ Metadata to change navbar, footer, and title , description SEO for your site folder location on `_data/metadata.json`

---

#### Thank You by using [JAMSTACK themes template]({{page.url}}) project

We hope with this source code you can build modern website blog for your project.
