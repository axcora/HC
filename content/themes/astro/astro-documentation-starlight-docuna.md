---
layout: themes-detil.cax
title: Docuna - Astro Starlight Docs Template - Documentation and Landing
description: Astro Starlight documentation template with landing page, search, sidebar nav, dark mode. Fast, SEO ready, MDX, own 100% source, one-time.
is_premium: true
price: $35
image: astro/starlighttemplate_uyq8cf.jpg
features:
  - Astro + Starlight
  - Documentation + Landing
  - Sidebar Nav + Search
  - Dark Mode + SEO Auto
  - MDX + Markdown
  - Contact Form
  - Responsive + Fast
  - Own 100% Source
faq:
  - q: "What is Docuna, and what problem does it solve?"
    a: "Docuna is a premium Astro Starlight documentation template. It ships with a documentation system, a landing page, sidebar navigation, search, dark mode, MDX and Markdown support, a contact form, and responsive output. Site configuration lives in astro.config.mjs, landing content in src/data/home/home.json, navbar and footer in src/data/config/config.json, and documentation articles in src/content/docs/. Instead of assembling a Starlight docs site and a landing page from scratch, you install the project, run npm run dev, and start editing JSON and Markdown."
  - q: "Do I need to know Astro or Starlight to use Docuna?"
    a: "You need Node.js and a terminal to install and run the project, but daily content editing happens through JSON, Markdown, and MDX files. Sidebar categories live in astro.config.mjs, landing content in src/data/home/home.json, and documentation articles in src/content/docs/. If you can edit JSON and Markdown, you can customize most of it. Basic Starlight knowledge helps if you want to extend the splash page templates."
  - q: "How do I install and run Docuna locally?"
    a: "Download and install Node.js from nodejs.org. Download the Docuna source code from Gumroad, create a new folder named docuna on your desktop, and extract the source into it. Open a terminal, run cd C:\Users\pcname\Desktop\docuna (replace pcname with your PC name), then run npm install and npm run dev. Open localhost:4321 in your browser."
  - q: "How do I configure the sidebar and documentation categories?"
    a: "Open astro.config.mjs with a code editor. Set site to your domain and title to your doc title. In the sidebar array, you can list items manually with label and link, or use autogenerate with a directory value to generate the sidebar from a folder. For example, { label: Project, autogenerate: { directory: project } } builds a section from the project folder inside src/content/docs/. To add a new documentation category, create a new folder inside src/content/docs/ and add .md files to it."
  - q: "How do I write a documentation article or a static page?"
    a: "For a documentation article, create a .md file inside a category folder in src/content/docs/ and add frontmatter with title and description, then write the body in Markdown. For a static page such as about or contact, create an .mdx file in src/content/docs/ with frontmatter including title, description, image, and template splash. The splash template imports Starlight components, the Picture component, the Conf config, and the Footer and Header widgets, which is why it produces a full-width landing-style page rather than a standard docs page."
  - q: "How do I update the landing page and navbar?"
    a: "Landing page content lives in src/data/home/home.json, with sections for intro, why, why_list, features, feature_list, pricing, plan, and section. Icons use Starlight icon names, so you can pick from the Starlight component icon list. Navbar and footer links live in src/data/config/config.json, with nav1, nav2, nav3, and nav4 groups, each with a title and a list of nav and link entries. Edit the JSON, save, and the dev server reflects the changes."
  - q: "Does Docuna include a CMS?"
    a: "Not pre-configured, but it supports several headless CMS options. Decap CMS works through the Netlify app, and you can also deploy the site on Netlify with Decap. Tina CMS is the best choice for local development mode. Cloudcannon is supported if you prefer it. Sveltia CMS and other Git-based headless CMS options also work. For teams that want a CMS out of the box, Nocturne is the better fit; for teams that prefer JSON and Markdown editing with optional CMS, Docuna is the lighter and more affordable option at 35 dollars."
  - q: "Is SEO handled automatically?"
    a: "Yes. Starlight and Astro handle the SEO pipeline: page titles and descriptions from frontmatter, canonical URLs from the site config, and Open Graph tags. The landing page JSON also carries title, description, and image fields, and the navbar and footer config includes a site description and image. Combined with the fast Astro static output and the responsive layout, the site is ready for search engines without manual meta wiring per page."
  - q: "How do I deploy Docuna?"
    a: "Push the project to a GitHub repository first, then register on Netlify, Vercel, or Cloudflare with your GitHub account, create a new project, connect your repository, and click deploy. To use a custom domain, change your domain nameservers to the hosting provider nameservers, following the provider documentation. For the Decap CMS option, Netlify is the recommended host because of its built-in Identity and Git Gateway."
  - q: "What is the license, and where can I see the demo and get support?"
    a: "Docuna is a one-time purchase at 35 dollars. You own 100 percent of the source, and you can use it on personal and client projects. The license does not permit reselling or redistributing the theme itself as a competing product. Live demo docuna.pages.dev. Download creativitaz.gumroad.com/l/docuna. For support, email creativebydre@gmail.com. Custom Astro and Starlight work is available through the Fiverr link in the article."
download: https://creativitaz.gumroad.com/l/docuna
demo: https://docuna.pages.dev/
tags:
    - astro
    - starlight
    - documentation template
    - docs template
    - astro template
    - documentation website
    - astro docs
    - premiumthemes
---
## Docuna Astro Starlight project

A project present by [creativitas](https://www.fiverr.com/creativitas)

Hire developer : [https://www.fiverr.com/users/creativitas](https://www.fiverr.com/users/creativitas)

---

## How to install docuna starlight astro js themes template

### Download Node JS

For first you need to download and install node js , so you can [download node js](https://nodejs.org/en/download/)

Download and install node js on your local devices.

### Download Docuna Project

Next you can download docuna source code project, you can [download docuna here](https://creativitaz.gumroad.com/l/docuna)

### Extract Docuna Project

After you have download and install node js , and download docuna source code project, next you can create new folder on desktop, name it your new folder with `docuna` , and extract docuna source code project in to your project folder / docuna folder.

### Install Docuna Project

Ok, now you can access docuna project on your desktop with terminal, so open terminal, and run command `cd/C:\Users\pcname\Desktop\docuna`.

Need to change `pcname` with your pc name , now you can install docuna project by run this command `npm install`

### Run Docuna Project

Ok, now we can run docuna project on your local devices, so run this command `npm run dev` , open `localhost:4321`

Congratulations, you have run docuna project on your local devices.

---

## Configuration

First you need to set up and configure your documentation site, make sure you have a list of content about your documentation project.

And then you can configure your sidebar site in `astro.config.mjs`

Open astro.config.mjs with code editor

### Add your domain

Insert your domain

```js
title: 'Your doc title here....',
```

### Configure sidebar

Configure sidebar doc page

```js
label: 'Your categories doc here...',
```

### Documentation content

Configure your documentation content

```js
items: [
{ label: 'Your content doc title...', link: 'URL Link for your documentation content article..' },
```

### Auto Generate

Use auto generate content from documentation folder

```js
{
label: 'Your Categories doc here...',
autogenerate: { directory: 'your folder doc here...' },
},
```

### Example Code

Complete code look like this

```js
export default defineConfig({
  site: 'your website domain here..',
  integrations: [
    starlight({
      title: 'Your doc title here....',
      social: {
        github: 'your github repo url here..',
      },
      sidebar: [
        {
          label: 'Your categories doc here...',
          items: [
            { label: 'Your content doc title...', link: 'URL Link for your documentation content article..' },
          ],
        },
        {
          label: 'Your Categories doc here...',
          autogenerate: { directory: 'your folder doc here...' },
        },
        {
          label: 'Project',
          autogenerate: { directory: 'project' },
        },
      ],
    }),
  ],
});
```

### Implementation Code

example implementation code

```js
export default defineConfig({
  site: 'https://astrodoc.pages.dev',
  integrations: [
    starlight({
      title: 'Docuna',
      social: {
        github: 'https://www.fiverr.com/creativitas',
      },
      sidebar: [
        {
          label: 'Getting Started',
          items: [
            { label: 'Welcome', link: '/getting-started/welcome/' },
            { label: 'Download', link: '/getting-started/download/' },
            { label: 'Installation', link: '/getting-started/installation/' },
            { label: 'Structure', link: '/getting-started/structure/' },
            { label: 'Configuration', link: '/getting-started/configuration/' },
            { label: 'Design UI', link: '/getting-started/design/' },
            { label: 'Content Doc', link: '/getting-started/content/' },
            { label: 'Static Page', link: '/getting-started/static-page/' },
            { label: 'Hosting Deploy', link: '/getting-started/hosting-deploy/' },
            { label: 'Headless CMS', link: '/getting-started/headlesscms/' },
          ],
        },
        {
          label: 'Source Code',
          autogenerate: { directory: 'sourcecode' },
        },
        {
          label: 'Project',
          autogenerate: { directory: 'project' },
        },
      ],
    }),
  ],
});
```

---

## How to update landing page starlight astro js project

For update design landing page UI, and configure your navbar or footer , you can access on `src/data/`

### Navbar Link

For update navbar menu link and footer area, you can access on `src/data/config/config.json`

### Home Landing Page

For update home landing page design ,you can access on `src/data/home/home.json`

You can update the landing page design in this area, just edit it according to your needs with json code.

For change icon you can see starlight component [https://starlight.astro.build/guides/components/#icon](https://starlight.astro.build/guides/components/#icon)

---

## How to write documentation content article

### Folder Location

For write content documentation, you can access on `src/content/docs`

### Categories Group

Now you can create category folders to group your documentation content articles.

for example the `getstart` folder for how to work with your project.

### Content Article

Next, you can create a content article, by creating a new .md markdown file, in the getstart folder.

### Example Content

Example we create `installation.md` for create installation documentation content , next you can add this frontmatter,

```js
---
title: Your title in here...
description: Description in here....
---
Write content with markdown concept here....
```

---

## How to create static page documentation starlight docuna

Folder Location

For create a new static page you can access on `src/content/docs`

Create New Page
And create your new static page with mdx format, for example `about.mdx`  for create your about page.

Frontmatter
Next you can insert this frontmatter in to your about.mdx or your new static page.

```js
---
title: "Insert title here...."
description: "Insert description here...."
image: "Insert URL image cover here..."
template: splash
---
```

---

## Hosting Deploy

For deploy your documentation website project, for first you need push your documentation website project in to github repo, just create github account and create new repo, then push your project in to your repo.

Next you can register on cloud modern hosting like netlify, vercel, cloudflare and others.

---

## Headless CMS

### Decap CMS
You can use decap cms by netlify app for integration your project with decap cms, and you can also deploy your website on netlify.

### Tina CMS
Tina is the best choice if you want integration your documentation website project, for dev mode or localdevices.

### Cloudcannon
You can also integration your website project with cloudcannon headless cms if you want to work with cms.
